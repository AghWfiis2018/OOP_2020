// *** Nie wolno modyfikować ***
#pragma once

#include <vector>
#include <algorithm>
#include "organism.h"
#include "virus.h"

using namespace std;


// ---------------------------------------------------------------------------------
// Dokonuje mutacji kodu genetycznego. Mutacja polega na powieleniu losowego 
// nukleotydu, zamazując następujący po nim.
//
DNA mutation(const DNA& dna) {
	// losujemy łańcuch nukleotydów, który ulegnie mutacji
	int l = rand()%2;
	// kopiujemy ten łańcuch (użycie konwersji klasy GeneSeq do std::vector)
	vector<Nucleotide> chain = dna[l];
	int s = chain.size();
	// losujmey nukleotyd podlegający powieleniu
	int k = rand()%s;
	// jeśli wylosowany jest ostatnim, brak mutacji
	if (k+1<s)
		chain[k+1] = chain[k];
	DNA dna_(chain,dna.get_chain(!l));
	return dna_;
}


// ---------------------------------------------------------------------------------
// Testuje obecność kodu genetycznego virusa w organizmie.
//
bool dna_test(const Organism& org, const Virus& vir) {
	// użycie konwersji klasy GeneSeq do std::vector
	vector< Nucleotide > vrna = *vir.get_RNA(); 
	for (int l=0; l<2; ++l) {
		// użycie operatora [] klasy DNA
		vector< Nucleotide > chain = org.get_dna()[l];
		// doklejamy kopię łańcucha na koniec 
		// (na wypadek, gdyby część kodu wirusa była na początku)
		chain.insert(chain.end(),chain.begin(),chain.end());
		// szukamy kodu wirusa
		if ( search( chain.begin(),chain.end(),
			     vrna.begin(),vrna.end(), 
			     [](Nucleotide n1, Nucleotide n2) { return n1==n2; } )
			    != chain.end() ) 
			return true;
	}
	return false;
}

