/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

	//OUR TESTS
	PhysicalNumber cm_length(500, Unit::CM);
	PhysicalNumber km_length(2, Unit::KM);
	PhysicalNumber m_length(100, Unit::M);
	PhysicalNumber sec_time(150, Unit::SEC);
	PhysicalNumber m_time(25, Unit::MIN);
	PhysicalNumber h_time(4, Unit::HOUR);
	PhysicalNumber ton(1, Unit::TON);
	PhysicalNumber kg(500, Unit::KG);



	testcase
		.setname("Basic output")
		.CHECK_OUTPUT(a, "2[km]")
		.CHECK_OUTPUT(b, "300[m]")

		.setname("Compatible dimensions")
		.CHECK_OUTPUT(b + a, "2300[m]")
		.CHECK_OUTPUT((a += b), "2.3[km]")
		.CHECK_OUTPUT(a, "2.3[km]")
		.CHECK_OUTPUT(a + a, "4.6[km]")
		.CHECK_OUTPUT(b - b, "0[m]")
		.CHECK_OUTPUT(c, "2[hour]")
		.CHECK_OUTPUT(d, "30[min]")
		.CHECK_OUTPUT(d + c, "150[min]")

		.setname("Incompatible dimensions")
		.CHECK_THROWS(a + c)
		.CHECK_THROWS(a + d)
		.CHECK_THROWS(b + c)
		.CHECK_THROWS(b + d)

		.setname("Basic input")
		.CHECK_OK(istringstream("700[kg]") >> a)
		.CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

		// YOUR TESTS - INSERT AS MANY AS YOU WANT

		.setname("first")
		.CHECK_OUTPUT(cm_length, "500[cm]")
		.CHECK_OUTPUT(cm_length + km_length, "200500[cm]")
		.CHECK_OUTPUT(sec_time + m_time, "1650[sec]")
		.CHECK_OUTPUT(m_time + sec_time, "27.5[min]")
		.CHECK_OUTPUT(ton - kg, "0.5[ton]")
		.CHECK_OUTPUT(km_length--, "2[km]")
		.CHECK_OUTPUT(m_length++, "100[m]")
		.CHECK_OUTPUT(sec_time--, "150[sec]")
		.CHECK_OUTPUT(km_length++, "1[km]")
		.CHECK_OUTPUT((km_length += m_length), "2.101[km]")
		.CHECK_OUTPUT((m_time -= sec_time), "22.5[min]")


		.setname("second")
		.CHECK_THROWS(cm_length + ton)
		.CHECK_THROWS(sec_time + km_length)
		.CHECK_THROWS(m_time + m_length)
		.CHECK_THROWS(kg + sec_time)
		.CHECK_THROWS(sec_time + ton)
		.CHECK_THROWS(kg + km_length)
		.CHECK_THROWS(m_time + m_length)
		.CHECK_THROWS(ton + h_time)
		.CHECK_THROWS(h_time + m_length)
		.CHECK_THROWS(km_length + h_time)
		.CHECK_THROWS(kg - km_length)
		.CHECK_THROWS(m_time - m_length)
		.CHECK_THROWS(ton - h_time)
		.CHECK_THROWS(h_time - m_length)
		.CHECK_THROWS(km_length - h_time)
		.CHECK_THROWS(istringstream("1[on]") >> ton)
		.CHECK_THROWS(istringstream("1ton") >> ton)
		.CHECK_THROWS(istringstream("23[cmm]") >> cm_length)
		.CHECK_THROWS(istringstream("1[k]") >> kg)
		.CHECK_THROWS(istringstream("1") >> sec_time)
		.CHECK_THROWS(istringstream("mnh") >> m_length)
		.CHECK_THROWS(istringstream("1[  ton  ]") >> ton)
		.CHECK_THROWS(istringstream("14kg") >> kg)
		.CHECK_THROWS(istringstream("strrrrrdfsfs") >> m_length)
		.CHECK_THROWS(istringstream("[[12]]") >> kg)
		.CHECK_THROWS(istringstream("1[min]") >> sec_time)

		.setname("third")
		.CHECK_OK(istringstream("700[kg]") >> kg)
		.CHECK_OK(istringstream("4[km]") >> km_length)
		.CHECK_OK(istringstream("60[sec]") >> sec_time)
		.CHECK_OK(istringstream("25[min]") >> m_time)
		.CHECK_OK(istringstream("50[cm]") >> cm_length)
		.CHECK_OK(istringstream("20[hour]") >> h_time)
		.CHECK_OK(istringstream("1[ton]") >> ton)
		

		.setname("fourth")

		.CHECK_OUTPUT(cm_length + km_length, "400050[cm]")
		.CHECK_OUTPUT(sec_time + m_time, "1560[cm]")
		.CHECK_OUTPUT(ton + kg, "1.7[ton]")
		.CHECK_OUTPUT(km_length + cm_length, "4.0005[km]")
		.CHECK_OUTPUT(h_time - m_time, "19.35[hour]")
		.CHECK_OUTPUT(kg + ton ,"1700[kg]")
		.CHECK_OUTPUT(m_time + h_time, "1161[min]")
		
		
		.setname("five")

		.CHECK_OUTPUT((--sec_time), "59[sec]")
		.CHECK_OUTPUT((sec_time--), "59[sec]")
		.CHECK_OUTPUT((++kg), "701[kg]")
		.CHECK_OUTPUT((m_time++), "25[min]")
		.CHECK_THROWS(cm_length + ton)
		.CHECK_THROWS(kg + sec_time)
		.CHECK_THROWS(h_time + cm_length)
		.CHECK_THROWS(cm_length + h_time)
		.CHECK_THROWS(km_length + kg)
		.CHECK_THROWS(m_length + ton)
		.CHECK_OUTPUT((-m_time), "-26[min]")
		.CHECK_OUTPUT((-m_time), "26[min]")
		.CHECK_OUTPUT((-sec_time), "-58[sec]")
		.CHECK_OUTPUT((-h_time), "-4[hour]")
		.CHECK_OUTPUT((+m_time), "26[min]")
		.CHECK_OUTPUT((+m_time), "26[min]")
		.CHECK_OUTPUT((+sec_time), "58[sec]")
		.CHECK_OUTPUT((+h_time), "20[min]")




		

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}