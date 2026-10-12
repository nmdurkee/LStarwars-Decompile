/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x7030ac; label: DNameNode::operator+=
 */

/* Library Function - Single Match
    public: class DNameNode & __thiscall DNameNode::operator+=(class DNameNode *)
   
   Library: Visual Studio 2005 Release */

DNameNode * __thiscall DNameNode::operator+=(DNameNode *this,DNameNode *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (DNameNode *)0x0) {
    iVar1 = *(int *)(this + 4);
    if (*(int *)(this + 4) == 0) {
      *(DNameNode **)(this + 4) = param_1;
    }
    else {
      do {
        iVar2 = iVar1;
        iVar1 = *(int *)(iVar2 + 4);
      } while (iVar1 != 0);
      *(DNameNode **)(iVar2 + 4) = param_1;
    }
  }
  return this;
}

