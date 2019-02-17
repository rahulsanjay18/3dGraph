#include <iostream>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/interpreter.h>
#include <string.h>

/*ExternalProject_Add(octave
	PREFIX .
    SOURCE_DIR .
	INSTALL_DIR .
    BUILD_COMMAND make -f ~/Documents/3dGraph/graph/mk)
*/
void math (void)
{
string_vector argv (2);
  argv(0) = "embedded";
  argv(1) = "-q";

  octave_main (2, argv.c_str_vec (), 1);

  octave_idx_type n = 2;
  octave_value_list in;

  for (octave_idx_type i = 0; i < n; i++)
    in(i) = octave_value (5 * (i + 2));

  octave_value_list out = feval ("gcd", in, 1);

  if (out.length () > 0)
    std::cout << "GCD of ["
              << in(0).int_value ()
              << ", "
              << in(1).int_value ()
              << "] is " << out(0).int_value ()
              << std::endl;
  else
    std::cout << "invalid\n";
}

void z_values(std::string eqn, int res, float startX, float startY, float dx, float dy, float** finalAnsArr){
	std::cout<<"1"<<"\n";	
  string_vector argv (2);
  argv(0) = "embedded";
  argv(1) = "-q";
std::cout<<"2"<<"\n";
  octave_main (2, argv.c_str_vec (), 1);
	// create instance of eqn
	std::cout<<"3"<<"\n";
	octave_value_list in;
	octave_idx_type n = 0;
	
	in(n) = octave_value(eqn);
	n = 1;
	in(n) = octave_value("x");
	n = 2;
	in(n) = octave_value("y");
	std::cout<<"4"<<"\n";
	octave_value_list eqnObj = feval("inline", in, 1);
	//calculate ranges
	float limposX = startX + res/2.0;
	float limposY = startY + res/2.0;
	float limnegX = startX - res/2.0;
	float limnegY = startY - res/2.0;
	
	
	// iterate based on range and populate array
	int i = 0;
	int j = 0;
	std::cout<<"5"<<"\n";
	// there is a redundancy issue here
	for(float x = limnegX; x <= limposX && i < res; x += dx){
		for(float y = limnegY; y <= limnegY && j < res; y += dy){
			finalAnsArr[i][j] = ((feval("subs", in, 1))(0)).float_value();
			j++;	
		}
		i++;
	}
}