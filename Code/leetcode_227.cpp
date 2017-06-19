class Solution {
public:
    int calculate(string s) {
        vector<int> opnums;
        vector<char> ops;
        
        int slen = s.length();
        int num = 0;
        for(int i = 0;i<slen;++i){
            if(s[i] == ' ')
                continue;
            if(!isdigit(s[i])){
                opnums.push_back(num);
                ops.push_back(s[i]);
                num = 0;
            }
            else
                num = num*10+s[i] - '0';
        }
        opnums.push_back(num);
        
        if(ops.size() < 1)
            return opnums[0];
        
        int opsidx = 1;
        int opnumsidx = 2;
        int opa = opnums[0];
        int opb = opnums[1];
        char op = ops[0];
        char opnex = 0;
        
        while(opsidx <= int(ops.size())){
            if(op == '+' || op == '-'){
                while(opsidx < int(ops.size())){
                    if(ops[opsidx] == '*' || ops[opsidx] == '/'){                    
                        opnex = ops[opsidx++];
                        int opc = opnums[opnumsidx++];
                        if(opnex == '*')
                            opb = opb * opc;
                        if(opnex == '/')
                            opb = opb / opc;
                    }
                    else 
                        break;
                }
                if(op == '+')
                    opa = opa+opb;
                if(op == '-')
                    opa = opa-opb;
            }
            if(op == '*')
                opa = opa * opb;
            if(op == '/')
                opa = opa / opb;
            opb = opnums[opnumsidx++];
            op = ops[opsidx++];
        }
        return opa;
    }
};