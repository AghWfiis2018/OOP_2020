#pragma once
// *** Nie wolno modyfikować tego pliku ***


#include <memory>
#include "rover.h"


/// Klasa typu proxy dostarczająca interfejs do klasy Rover.
/// Nie można używać klasy Rover bez interfejsu.
class RoverIface: public Rover {

 public:	

	/// odczyt współrzędnych
 	Coordinates get_coordinates() const {
		return rover->get_coordinates(); }

	/// uzyskanie nazwy interfejs+łazik
	std::string get_name() const {
		return name+"@"+rover->get_name(); }

	/// wykonuje pojedyńczą akcję daną bezargumentowym obiektem 
	/// wykonywalnym o typie zwracanym void
	void execute(const std::function< void() > action_) {
		rover->execute(action_); }

	/// Wykonuje ciąg instrukcji zmieniających współrzędne.
	/// 'Program' jest aliasem typu będącym wektorem bezargumentowych obiektów
	/// wykonywalnych, zwracających std::vector< double >, o który zmieniane są współrzędne.
	void drive(const Program& progr_) {
		rover->drive(progr_); }

	/// Ustawia współrzędne łazika na podane jako arugment.
	void calibrate(const Coordinates& coords_) {
		rover->coordinates = coords_; } 

	/// Konstruktor pobiera wskaźnik do łazika oraz nazwę interfejsu/operatora.
	RoverIface(Rover* rover_, std::string iface_name_):
		rover(rover_) {
			rover->online = true; // ustawiamy flagę linkowania z interfejsem
			name = iface_name_;
			msg_online();	}


 private:

	std::unique_ptr< Rover > rover;

	void msg_online() const {
		std::cout << "Linking interface:" << name << " to rover:" << rover->name << "...\n";
	       	std::cout << rover->name << " is now online.\n"; }	
};