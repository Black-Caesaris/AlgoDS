class Tokenizer {
        vector<string> tokens;
        char delimiter;
    
    public:
        Tokenizer(char delimiter) {
            this->delimiter = delimiter;
        }
    
        vector<string> tokenize(string s) {
            this->tokens = {};
            string token;
            stringstream stream(s);
            while(getline(stream, token, delimiter)) {
                if(token == "")
                    continue;
                this->tokens.push_back(token);
            }
            return this->tokens;
        }
};

class File {
    public:
        string content;
        string name;
        
    File(string name) {
        this->content = "";
        this->name = name;
    }
    
    string addContent(string s) {
        this->content += s;
        return getContent();
    }
    
    string getContent() {
        return this->content;
    }
};

class Directory {    
    public:
        unordered_map<string, Directory*> directories;
        unordered_map<string, File*> files;
        string name;
        bool isFile;
     
    Directory(string name) {
        this->name = name;
        this->isFile = false;
    }
    
    Directory* getDirectory(string name) {
        if(this->directories.count(name))
            return this->directories[name];
        return nullptr;
    }
    
    void putDirectory (string name) {
        this->directories.insert({name, new Directory(name)});
    }
    
    File* getFile(string name) {
        if(this->files.count(name))
            return this->files[name];
        return nullptr;
    }
    
    void putFile(string name) {
        this->files.insert({name, new File(name)});
    }
    
    set<string> getContents () {
        set<string> contents;
        
        for(auto file : this->files) {
            contents.insert(file.first);
        }
        
        for(auto directory : this->directories) {
            contents.insert(directory.first);
        }
        
        return contents;
    }
    
};



class FileSystem {
public:
    
    Directory* root;
    Tokenizer* tokenizer;
    
    FileSystem() {
        root = new Directory("/");
        this->tokenizer = new Tokenizer('/');
    }
    
    vector<string> ls(string path) {
        vector<string> tokens = tokenizer->tokenize(path);
        Directory* node = root;

        for(auto& token : tokens) {
            if(!node->getDirectory(token)) {
                // means its a file
                return {token};
            }
            node = node->getDirectory(token);
            cout << node->name << endl;
        }
                
        set<string> contents =  node->getContents();
        vector<string> result(begin(contents), end(contents));
        
        return result; ;
    }
    
    void mkdir(string path) {
        vector<string> tokens = tokenizer->tokenize(path);
        Directory* node = root;
        
        for(auto& token : tokens) {
            if(!node->getDirectory(token)) {
                node->putDirectory(token);
            }
            node = node->getDirectory(token);
        }        
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> tokens = tokenizer->tokenize(filePath);
        Directory* node = root;
        for(auto& token : tokens) {
            if(!node->getDirectory(token)) {
                // means its a file
                File* file = node->getFile(token);
                if(file == nullptr) {
                    node->putFile(token);
                    file = node->getFile(token);
                }
                file->addContent(content); 
                return;
            }
            node = node->getDirectory(token);
        }
    }
    
    string readContentFromFile(string filePath) {
        vector<string> tokens = tokenizer->tokenize(filePath);
        Directory* node = root;
        for(auto& token : tokens) {
            if(!node->getDirectory(token)) {
                // means its a file
                File* file = node->getFile(token);
                return file->getContent();
            }
            node = node->getDirectory(token);
        }
        return "";
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */