#pragma once

// *** Nie wolno modyfikować tego pliku ***

#include <vector>
#include <ostream>


//-------------------------------------------------------------
// Implementacja nukleotydów
enum Nucleotide { 
	A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
};


//-------------------------------------------------------------
// Implementacja sekwencji nukleotydów
// danych typem Nucleotide.
class GeneSeq {

	// operator drukujący sekwencję genów na wyjście ostream.
	friend std::ostream& operator<<( std::ostream& out, const GeneSeq& seq_);

 public:	

	// zwraca sekwencję genów (nukleotydów) w postaci wektora
	std::vector< Nucleotide > get_sequence() const { return chain; }

	GeneSeq( const std::vector< Nucleotide > seq_ ): chain(seq_) { }

 protected:

	// ciąg nukleotydów zaimplementowany jako wektor	
	std::vector< Nucleotide > chain;

};