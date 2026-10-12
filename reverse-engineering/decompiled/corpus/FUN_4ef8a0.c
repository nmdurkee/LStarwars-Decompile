/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ef8a0; label: FUN_004ef8a0
 */

void FUN_004ef8a0(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  int *in_EAX;
  int iVar3;
  uint uVar4;
  int *in_EDX;
  uint uVar5;
  
  iVar3 = (*param_1 & 0x7fffffff) - *param_2;
  uVar4 = iVar3 - 0x10;
  *in_EDX = (int)param_1;
  iVar3 = iVar3 + (int)param_1;
  *in_EAX = iVar3;
  if (param_3 != 0) {
    iVar1 = iVar3 + 0xc;
    uVar5 = iVar3 + 0xb + param_3 & ~(param_3 - 1U);
    *in_EAX = (iVar3 - iVar1) + uVar5;
    *param_2 = *param_2 + (iVar1 - uVar5);
    uVar4 = uVar4 + (uVar5 - iVar1);
  }
  *(uint *)*in_EAX = *(uint *)*in_EAX | 0x80000000;
  *(uint *)*in_EAX = *(uint *)*in_EAX & 0x80000000 | *param_2;
  *(undefined4 *)(*in_EAX + 4) = 0;
  *(undefined4 *)(*in_EAX + 8) = 0;
  puVar2 = (uint *)*in_EAX;
  *(uint **)((*puVar2 & 0x7fffffff) + 0xc + (int)puVar2) = puVar2;
  *(uint *)*in_EDX = *(uint *)*in_EDX & 0x7fffffff;
  *(uint *)*in_EDX = *(uint *)*in_EDX & 0x80000000 | uVar4;
  *(undefined4 *)(*in_EDX + 4) = 0;
  *(undefined4 *)(*in_EDX + 8) = 0;
  puVar2 = (uint *)*in_EDX;
  *(uint **)((*puVar2 & 0x7fffffff) + 0xc + (int)puVar2) = puVar2;
  return;
}

