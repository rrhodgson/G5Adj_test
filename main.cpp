#include <Grid/Grid.h>

using namespace std;
using namespace Grid;

int main (int argc, char ** argv)
{
	Grid_init(&argc,&argv);
	
	auto grid = SpaceTimeGrid::makeFourDimGrid(GridDefaultLatt(), GridDefaultSimd(Nd,vComplexD::Nsimd()),GridDefaultMpi());
	
	Gamma g5(Gamma::Algebra::Gamma5);

	LatticePropagator q(grid);
	q = 1.0;
	
	auto              qAdj1 = adj(q) * g5; // LatticeBinaryExpression
	LatticePropagator qAdj2 = qAdj1;       // evaluate lvalue expression
	LatticePropagator qAdj3 = adj(q) * g5; // evaluate rvalue expression
	
	std::cout << "|q|^2         = " << norm2(q) << std::endl;
	std::cout << "|adj(q)*g5|^2 = " << norm2(adj(q)*g5) << std::endl;
	std::cout << "|qAdj1|^2     = " << norm2(qAdj1) << std::endl;
        std::cout << "|qAdj2|^2     = " << norm2(qAdj2) << std::endl;
        std::cout << "|qAdj3|^2     = " << norm2(qAdj3) << std::endl;

	Grid_finalize();
}
