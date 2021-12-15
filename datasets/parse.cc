{

    TDOMParser* parser = new TDOMParser();
    parser->SetValidate(false);
    parser->ParseFile("training_methods.xml");
    
    auto* node = parser->GetXMLDocument()->GetRootNode();
    node = node->GetChildren()->GetNextNode();

    TList* attr_list;

    for (; node; node = node->GetNextNode()) {
        if (node->GetNodeType() == TXMLNode::kXMLElementNode) {
            attr_list = node->GetAttributes();
            std::cout << ((TXMLAttr*)attr_list->At(1))->GetValue() << std::endl;
        }
    }
}