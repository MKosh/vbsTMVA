#include <memory>

#include "TFile.h"
#include "TTree.h"
#include "TList.h"

void CombineYears() {
    std::unique_ptr<TList> train_list(new TList());
    std::unique_ptr<TList> test_list(new TList());
    std::unique_ptr<TList> data_list(new TList());

    std::unique_ptr<TFile> file_2016(TFile::Open("vbs_ww_2016_SBtmva.root"));
    std::unique_ptr<TTree> train_tree_2016(file_2016->Get<TTree>("vbs_ww_2016/TrainTree"));
    std::unique_ptr<TTree> test_tree_2016(file_2016->Get<TTree>("vbs_ww_2016/TestTree"));
    std::unique_ptr<TTree> data_tree_2016(file_2016->Get<TTree>("vbs_ww_2016/DataTree"));

    std::unique_ptr<TFile> file_2017(TFile::Open("vbs_ww_2017_SBtmva.root"));
    std::unique_ptr<TTree> train_tree_2017(file_2017->Get<TTree>("vbs_ww_2017/TrainTree"));
    std::unique_ptr<TTree> test_tree_2017(file_2017->Get<TTree>("vbs_ww_2017/TestTree"));
    std::unique_ptr<TTree> data_tree_2017(file_2017->Get<TTree>("vbs_ww_2017/DataTree"));

    std::unique_ptr<TFile> file_2018(TFile::Open("vbs_ww_2018_SBtmva.root"));
    std::unique_ptr<TTree> train_tree_2018(file_2018->Get<TTree>("vbs_ww_2018/TrainTree"));
    std::unique_ptr<TTree> test_tree_2018(file_2018->Get<TTree>("vbs_ww_2018/TestTree"));
    std::unique_ptr<TTree> data_tree_2018(file_2018->Get<TTree>("vbs_ww_2018/DataTree"));

    train_list->Add(train_tree_2016.get());
    train_list->Add(train_tree_2017.get());
    train_list->Add(train_tree_2018.get());

    test_list->Add(test_tree_2016.get());
    test_list->Add(test_tree_2017.get());
    test_list->Add(test_tree_2018.get());

    data_list->Add(data_tree_2016.get());
    data_list->Add(data_tree_2017.get());
    data_list->Add(data_tree_2018.get());

    std::unique_ptr<TFile> run2_summed(TFile::Open("vbs_ww_Run2_Summed_SBtmva.root", "RECREATE"));
    run2_summed->mkdir("vbs_ww_Run2_Summed");
    run2_summed->cd("vbs_ww_Run2_Summed");
    std::unique_ptr<TTree> output_train(TTree::MergeTrees(train_list.get()));
    std::unique_ptr<TTree> output_test(TTree::MergeTrees(test_list.get()));
    std::unique_ptr<TTree> output_data(TTree::MergeTrees(data_list.get()));
}