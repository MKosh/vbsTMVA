#include <memory>
#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TList.h"

void CombineYears() {
    /*std::unique_ptr<TList> train_list(new TList());
    std::unique_ptr<TList> test_list(new TList());
    std::unique_ptr<TList> data_list(new TList());*/
    TList* train_list = new TList();
    TList* test_list = new TList();
    TList* data_list = new TList();

    std::cout << "Getting Files and trees" << std::endl;
    std::unique_ptr<TFile> file_2016(TFile::Open("vbs_ww_2016_wv_SR_SBtmva.root"));
    /*std::unique_ptr<TTree> train_tree_2016(file_2016->Get<TTree>("vbs_ww_2016_wv_SR/TrainTree"));
    std::unique_ptr<TTree> test_tree_2016(file_2016->Get<TTree>("vbs_ww_2016_wv_SR/TestTree"));
    std::unique_ptr<TTree> data_tree_2016(file_2016->Get<TTree>("vbs_ww_2016_wv_SR/DataTree"));*/
    auto train_tree_2016 = file_2016->Get<TTree>("vbs_ww_2016_wv_SR/TrainTree");
    auto test_tree_2016 = file_2016->Get<TTree>("vbs_ww_2016_wv_SR/TestTree");
    auto data_tree_2016 = file_2016->Get<TTree>("vbs_ww_2016_wv_SR/DataTree");

    std::unique_ptr<TFile> file_2017(TFile::Open("vbs_ww_2017_wv_SR_SBtmva.root"));
    /*std::unique_ptr<TTree> train_tree_2017(file_2017->Get<TTree>("vbs_ww_2017_wv_SR/TrainTree"));
    std::unique_ptr<TTree> test_tree_2017(file_2017->Get<TTree>("vbs_ww_2017_wv_SR/TestTree"));
    std::unique_ptr<TTree> data_tree_2017(file_2017->Get<TTree>("vbs_ww_2017_wv_SR/DataTree"));*/
    auto train_tree_2017 = file_2017->Get<TTree>("vbs_ww_2017_wv_SR/TrainTree");
    auto test_tree_2017 = file_2017->Get<TTree>("vbs_ww_2017_wv_SR/TestTree");
    auto data_tree_2017 = file_2017->Get<TTree>("vbs_ww_2017_wv_SR/DataTree");

    std::unique_ptr<TFile> file_2018(TFile::Open("vbs_ww_2018_wv_SR_SBtmva.root"));
    /*std::unique_ptr<TTree> train_tree_2018(file_2018->Get<TTree>("vbs_ww_2018_wv_SR/TrainTree"));
    std::unique_ptr<TTree> test_tree_2018(file_2018->Get<TTree>("vbs_ww_2018_wv_SR/TestTree"));
    std::unique_ptr<TTree> data_tree_2018(file_2018->Get<TTree>("vbs_ww_2018_wv_SR/DataTree"));*/
    auto train_tree_2018 = file_2018->Get<TTree>("vbs_ww_2018_wv_SR/TrainTree");
    auto test_tree_2018 = file_2018->Get<TTree>("vbs_ww_2018_wv_SR/TestTree");
    auto data_tree_2018 = file_2018->Get<TTree>("vbs_ww_2018_wv_SR/DataTree");

    std::cout << "Adding trees to lists" << std::endl;
    /*train_list->Add(train_tree_2016.get());
    train_list->Add(train_tree_2017.get());
    train_list->Add(train_tree_2018.get());

    test_list->Add(test_tree_2016.get());
    test_list->Add(test_tree_2017.get());
    test_list->Add(test_tree_2018.get());

    data_list->Add(data_tree_2016.get());
    data_list->Add(data_tree_2017.get());
    data_list->Add(data_tree_2018.get());*/

    train_list->Add(train_tree_2016);
    train_list->Add(train_tree_2017);
    train_list->Add(train_tree_2018);

    test_list->Add(test_tree_2016);
    test_list->Add(test_tree_2017);
    test_list->Add(test_tree_2018);

    data_list->Add(data_tree_2016);
    data_list->Add(data_tree_2017);
    data_list->Add(data_tree_2018);

    std::cout << "Creating output file" << std::endl;
    std::unique_ptr<TFile> run2_summed(TFile::Open("vbs_ww_Run2_Summed_SBtmva.root", "RECREATE"));
    run2_summed->mkdir("vbs_ww_Run2_Summed");
    run2_summed->cd("vbs_ww_Run2_Summed");

    std::cout << "Merging and writing trees" << std::endl;
    std::unique_ptr<TTree> output_train(TTree::MergeTrees(train_list));
    //output_train->Write();
    std::unique_ptr<TTree> output_test(TTree::MergeTrees(test_list));
    //output_test->Write();
    //std::unique_ptr<TTree> output_data(TTree::MergeTrees(data_list));
    //output_data->Write();

    std::cout << "Done!" << std::endl;
}