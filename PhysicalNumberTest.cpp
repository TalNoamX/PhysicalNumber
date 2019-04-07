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
	PhysicalNumber km_length(2, Unit::CM);
	PhysicalNumber m_length(100, Unit::CM);
	PhysicalNumber sec_time(150, Unit::CM);
	PhysicalNumber m_time(25, Unit::CM);
	PhysicalNumber h_time(4, Unit::CM);
	PhysicalNumber ton(1, Unit::TON);
	PhysicalNumber kg(500, Unit::KG);



    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("first")
		.CHECK_OUTPUT(cm_length,"500[m]")
		.CHECK_OUTPUT(cm_length+km_length, "2500[m]")
		.CHECK_OUTPUT(sec_time+m_time, "1650[sec]")
		.CHECK_OUTPUT(m_time+sec_time, "27.5[m]")
		.CHECK_OUTPUT(ton-kg, "0.5[kg]")
		.CHECK_OUTPUT(km_length--, "1[km]")
		.CHECK_OUTPUT(m_length++, "101[m]")
		.CHECK_OUTPUT(sec_time--, "149[sec]")
		.CHECK_OUTPUT(km_length++, "2[km]")
		.CHECK_OUTPUT((km_length+= m_length), "2.101[km]")
		.CHECK_OUTPUT((m_time-=sec_time), "22.5[m]")


		.setname("second")
		.CHECK_THROWS(cm_length+ton)
		.CHECK_THROWS(sec_time+km_length)
		.CHECK_THROWS(m_time + m_length)
		.CHECK_THROWS(kg + sec_time)
		.CHECK_THROWS(sec_time + kg)

		.setname("third")
		.CHECK_OK(istringstream("700[kg]") >> kg)
		.CHECK_OK(istringstream("100[m]") >> m_time)
		.CHECK_OK(istringstream("2[ton]") >> ton)
		.CHECK_OK(istringstream("7[sec_time]") >> sec)

		

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}