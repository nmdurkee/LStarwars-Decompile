/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x703673; label: pDNameNode::getString
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

/* Library Function - Single Match
    public: virtual char * __thiscall pDNameNode::getString(char *,int)const 
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

char * __thiscall pDNameNode::getString(pDNameNode *this,char *param_1,int param_2)

{
  char *pcVar1;
  
  if (((*(DName **)(this + 8) != (DName *)0x0) && (param_1 != (char *)0x0)) && (param_2 != 0)) {
    pcVar1 = DName::getString(*(DName **)(this + 8),param_1,param_2);
    return pcVar1;
  }
  return (char *)0x0;
}

