/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703bb1; label: FUN_00703bb1
 */

void FUN_00703bb1(DName *param_1)

{
  int iVar1;
  DNameStatus DVar2;
  pDNameNode *this;
  DNameNode *pDVar3;
  DNameNode *this_00;
  DName *in_ECX;
  DName *this_01;
  
  if (param_1 == (DName *)0x0) {
    return;
  }
  iVar1 = DName::isEmpty(in_ECX);
  if (iVar1 != 0) {
    DName::operator=(this_01,param_1);
    return;
  }
  DVar2 = (*(int *)(param_1 + 4) << 0x1c) >> 0x1c;
  if ((DVar2 != 0) && (DVar2 != 2)) {
    DName::operator+=(this_01,DVar2);
    return;
  }
  this = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0xc,0);
  if (this == (pDNameNode *)0x0) {
    pDVar3 = (DNameNode *)0x0;
  }
  else {
    pDVar3 = (DNameNode *)pDNameNode::pDNameNode(this,param_1);
  }
  if (pDVar3 == (DNameNode *)0x0) {
    *(undefined4 *)in_ECX = 0;
  }
  else {
    this_00 = DNameNode::clone(*(DNameNode **)in_ECX);
    *(DNameNode **)in_ECX = this_00;
    if (this_00 == (DNameNode *)0x0) goto LAB_00703c29;
    DNameNode::operator+=(this_00,pDVar3);
  }
  if (*(int *)in_ECX != 0) {
    return;
  }
LAB_00703c29:
  *(uint *)(in_ECX + 4) = *(uint *)(in_ECX + 4) & 0xfffffff3 | 3;
  return;
}

