/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703dde; label: DName::operator+=
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator+=(char)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator+=(DName *this,char param_1)

{
  int iVar1;
  DNameNode *pDVar2;
  DName *this_00;
  
  if (param_1 != '\0') {
    iVar1 = isEmpty(this);
    if (iVar1 == 0) {
      pDVar2 = DNameNode::clone(*(DNameNode **)this);
      *(DNameNode **)this = pDVar2;
      if (pDVar2 == (DNameNode *)0x0) {
        *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff3 | 3;
      }
      else {
        pDVar2 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0xc,0);
        if (pDVar2 == (DNameNode *)0x0) {
          pDVar2 = (DNameNode *)0x0;
        }
        else {
          *(undefined4 *)(pDVar2 + 4) = 0;
          *(undefined ***)pDVar2 = &PTR_LAB_00780ebc;
          pDVar2[8] = (DNameNode)param_1;
        }
        DNameNode::operator+=(*(DNameNode **)this,pDVar2);
      }
    }
    else {
      operator=(this_00,param_1);
    }
  }
  return this;
}

