/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703855; label: DName::doPchar
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: void __thiscall DName::doPchar(char const *,int)
   
   Library: Visual Studio 2005 Release */

void __thiscall DName::doPchar(DName *this,char *param_1,int param_2)

{
  char cVar1;
  pcharNode *this_00;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(this + 4);
  iVar4 = (int)(uVar3 << 0x1c) >> 0x1c;
  if (iVar4 == 1) {
    return;
  }
  if (iVar4 == 3) {
    return;
  }
  if (*(int *)this != 0) {
    operator=(this,3);
    return;
  }
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    uVar3 = uVar3 & 0xfffffff1 | 1;
    goto LAB_007038f2;
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      puVar2 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0xc,0);
      if (puVar2 == (undefined4 *)0x0) goto LAB_007038be;
      cVar1 = *param_1;
      puVar2[1] = 0;
      *puVar2 = &PTR_LAB_00780ebc;
      *(char *)(puVar2 + 2) = cVar1;
    }
    else {
      this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0x10,0);
      if (this_00 == (pcharNode *)0x0) {
LAB_007038be:
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = (undefined4 *)pcharNode::pcharNode(this_00,param_1,param_2);
      }
    }
    *(undefined4 **)this = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      return;
    }
    uVar3 = *(uint *)(this + 4);
  }
  uVar3 = uVar3 & 0xfffffff3 | 3;
LAB_007038f2:
  *(uint *)(this + 4) = uVar3;
  return;
}

