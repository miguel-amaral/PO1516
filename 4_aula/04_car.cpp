#include <stdlib.h>
#include <stdio.h>
#include <iostream>

/****************************************************/
/******************** ENGINE **********************/
/************************************************/
class Engine{
public:
  virtual void on() {
      std::cout << "Engine \e[32mON!\e[0m" << std::endl ;
        }
	  virtual void off() {
	      std::cout << "Engine \e[31mOFF!\e[0m" << std::endl ;
	        }
		};

		class Basic_Engine : public Engine{
		public:
		  virtual void on() {
		      std::cout << "Basic Engine \e[32mON!\e[0m" << std::endl ;
		        }
			  virtual void off() {
			      std::cout << "Basic Engine \e[31mOFF!\e[0m" << std::endl ;
			        }
				};
				class Xtreme : public Engine{
				public:
				  void on() {
				      std::cout << "Xtreme \e[32mON!\e[0m" << std::endl ;
				        }
					  void off() {
					      std::cout << "Xtreme \e[31mOFF!\e[0m" << std::endl ;
					        }
						};
						/***************************************************/
						/********************* CAR ***********************/
						/***********************************************/

						class Car{
						  Engine* _engine;
						  public:
						    Car(Engine *engine):_engine(engine){}

						      void setEngine(Engine *engine) {_engine = engine; }
						        Engine* getEngine()            { return _engine; }

							  void go() {
							      getEngine()->on();
							        }
								  void stop(){
								      getEngine()->off();
								        }
									};

									class CarMidrange : public Car{
									public:
									  CarMidrange(Engine *engine): Car(engine) {}

									    void updateEngine(Basic_Engine *engine) {
									        setEngine(engine);
										  }
										  };

										  class CarTop : public CarMidrange{
										    Xtreme *_xtreme;
										    public:
										      CarTop(Engine *engine): CarMidrange(engine) {}
										        void addXtra(Xtreme *xtreme) {
											    _xtreme = xtreme;
											      }
											        void go() {
												    CarMidrange::go();
												        if(_xtreme != NULL)    _xtreme->on();
													  }
													    void stop() {
													        CarMidrange::stop();
														    if(_xtreme != NULL)    _xtreme->off();
														      }
														      };
														      int main() {
														        Engine *low_eng = new Engine();
															  Basic_Engine* mid_eng = new Basic_Engine();
															    Xtreme *xtreme = new Xtreme();

															      Car c1 (low_eng);
															        CarMidrange c2 (low_eng);
																  CarTop c3(new Xtreme());
																    std::cout << "c1" << std::endl;
																      c1.go();
																        c1.stop();
																	  std::cout << "\nc2" << std::endl;
																	    c2.go();
																	      c2.stop();
																	        std::cout << "\nc3" << std::endl;
																		  c3.go();
																		    c3.stop();


																		      c2.updateEngine(mid_eng);
																		        c3.updateEngine(mid_eng);
																			  std::cout << "\n\e[33mMid engine updated\e[0m\n" << std::endl;

																			    std::cout << "c1" << std::endl;
																			      c1.go();
																			        c1.stop();
																				  std::cout << "\nc2" << std::endl;
																				    c2.go();
																				      c2.stop();
																				        std::cout << "\nc3" << std::endl;
																					  c3.go();
																					    c3.stop();

																					      c3.addXtra(xtreme);
																					        std::cout << "\n\e[33mAdd xtra\e[0m\n" << std::endl;
																						  std::cout << "c1" << std::endl;
																						    c1.go();
																						      c1.stop();
																						        std::cout << "\nc2" << std::endl;
																							  c2.go();
																							    c2.stop();
																							      std::cout << "\nc3" << std::endl;
																							        c3.go();
																								  c3.stop();
																								  }

