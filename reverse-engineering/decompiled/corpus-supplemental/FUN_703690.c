/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x703690; label: DNameStatusNode::getString
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

/* Library Function - Single Match
    public: virtual char * __thiscall DNameStatusNode::getString(char *,int)const 
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

char * __thiscall DNameStatusNode::getString(DNameStatusNode *this,char *param_1,int param_2)

{
  char *pcVar1;
  uint unaff_retaddr;
  
  if ((int)*(char **)(this + 0xc) < param_2) {
    param_2 = (int)*(char **)(this + 0xc);
  }
  pcVar1 = (char *)0x0;
  if (((*(int *)(this + 8) == 2) && (param_1 != (char *)0x0)) && ((char *)param_2 != (char *)0x0)) {
    pcVar1 = und_strncpy(param_1,(char *)param_2,unaff_retaddr);
  }
  return pcVar1;
}

