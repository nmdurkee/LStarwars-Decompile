/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x7035ad; label: pcharNode::pcharNode
 */

/* Library Function - Single Match
    public: __thiscall pcharNode::pcharNode(char const *,int)
   
   Library: Visual Studio 2005 Release */

pcharNode * __thiscall pcharNode::pcharNode(pcharNode *this,char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  uint unaff_EDI;
  
  *(undefined4 *)(this + 4) = 0;
  *(undefined ***)this = &PTR_LAB_00780eec;
  if (param_2 == 0) {
    if (param_1 == (char *)0x0) goto LAB_00703604;
    param_2 = 0;
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      param_2 = param_2 + 1;
      cVar1 = *(char *)(param_2 + (int)param_1);
    }
    if ((char *)param_2 == (char *)0x0) goto LAB_00703604;
  }
  if (param_1 != (char *)0x0) {
    pcVar2 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,param_2,0);
    *(char **)(this + 8) = pcVar2;
    *(int *)(this + 0xc) = param_2;
    if (pcVar2 == (char *)0x0) {
      return this;
    }
    und_strncpy(pcVar2,(char *)param_2,unaff_EDI);
    return this;
  }
LAB_00703604:
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return this;
}

