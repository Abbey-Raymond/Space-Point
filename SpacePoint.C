#define SpacePoint_cxx
#include "SpacePoint.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void SpacePoint::Loop()
{

TH1D *hTrackZ = new TH1D ("hTrackZ", "Space Point Z; Z; Counts", 100, 1, 0); 
//   In a ROOT session, you can do:
//      root> .L SpacePoint.C
//      root> SpacePoint t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch



   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   std::cout<<"Number of Events ="<<nentries<<std::endl; 

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry ++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;



   std::cout<<"Run "<<run<<", Subrun "<< ", Event"<<event<<std::endl; 
//tells the code to print the event runs 

   for(int aa=0; aa<nclus; aa++)
      {// start of aa for loop
       std::cout<<"Cluster starting wire number "<<clustertwire[aa]<<std::endl; 
       // get cluster wire start number
      
       std::cout<<"Plane Number "<<cluplane[aa]<<std::endl; 
       // plane number of a given cluster value 
        
	}// <-- end of aa for loop




   for (int ntrk=0; ntrk<ntracks_reco; ntrk++)
      {// start of ntrk for loop
      hTrackZ->Fill(trkvtxz[ntrk]); 

       for (int spacepoints=0; spacepoints<ntrkhits[ntrk]; spacepoints++)
           { // start spacepoints for loop
           
            std::cout<<"Z SpacePoint "<<trkz[ntrk][spacepoints]<<std::endl; 
            }//<-- end spacepoints for loop


      }//<-- end of ntrk for loop
   }//<-- end jentry for loop 

hTrackZ->SetFillColor(kBlue-7); 
hTrackZ-> Draw(); 

}// <-- end of void Spacepoint::Loop()
