/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x703112; label: pDNameNode::pDNameNode
 */

/* Library Function - Single Match
    public: __thiscall pDNameNode::pDNameNode(class DName *)
   
   Library: Visual Studio 2005 Release */

void __thiscall pDNameNode::pDNameNode(pDNameNode *this,DName *param_1)

{
  int iVar1;
  
  *(undefined4 *)(this + 4) = 0;
  *(undefined ***)this = &PTR_LAB_00780ecc;
  if ((param_1 != (DName *)0x0) &&
     ((iVar1 = (*(int *)(param_1 + 4) << 0x1c) >> 0x1c, iVar1 == 1 || (iVar1 == 3)))) {
    param_1 = (DName *)0x0;
  }
  *(DName **)(this + 8) = param_1;
  return;
}

