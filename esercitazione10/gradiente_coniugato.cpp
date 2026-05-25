#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include <cmath>

int main(int argc, char **argv) 

//cicliamo sulle dimensioni del vettore
{for(unsigned int n = 2; n<20; n++){

  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

  if (std::abs(B.determinant()) < 1.0e-15)
    continue; //non faccio return -1 perchè mi basa passare alla prossima dimensione qui, non devo fare fallire tutto il codice

  Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

  Eigen::VectorXd b = A * x_ex;

  Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
  Eigen::VectorXd res = b - A * x;
  Eigen::VectorXd p = res;
  double res_norm_0 = res.norm();

  const unsigned int k_max = 10000;
  unsigned int k = 0;
  const double res_tol = 1.0e-12;

  while (k < k_max &&
         res.norm() > res_tol * res_norm_0)
  {
    
    const double alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value();;

	x = x + alpha_k * p;
	
	res = b - A * x;
	
	const double beta_k = ((p.transpose() * A * res ) / (p.transpose() * A * p)).value();;
	
	p = res - beta_k * p;

	
    k++;
  }

  const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() :
                                              (x - x_ex).norm() / x_ex.norm();

  const double tol = 1.0e-10; //tolleranza scelta arbitrariamente da me, non posso scegliere qualcosa della grandezza di e-15 se no mi verrebbe quasi sempre false, devo rilassare un po' la richiesta

  //Qui aggiungo la parte di test, guardo se l'errore relativo è grande e, nel caso, esco dal ciclo.
  if (err_rel>tol){
	  return EXIT_FAILURE;
  }
 }
 return EXIT_SUCCESS;	
}
