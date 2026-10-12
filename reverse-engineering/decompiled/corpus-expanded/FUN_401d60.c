/* Ghidra pseudocode, not original source.
 * ev_48d4eb782bac12eedeead3c338e4f978b0df7732be8621fd20cf56d53bd7b1ed
 * Entry: 0x401d60; label: FUN_00401d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00401d60(void)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)((int)in_EAX + 6);
  if (uVar2 == DAT_007faaa4) {
    if (((char)*(ushort *)(*in_EAX + 0x94) < '\0') && ((*(ushort *)(*in_EAX + 0x94) & 2) == 0)) {
      return 1;
    }
  }
  else if (uVar2 == DAT_00802644) {
    if (((*(byte *)(*in_EAX + 0x94) & 1) != 0) && (*(int *)(*(int *)(*in_EAX + 0x34) + 0xc) != 2)) {
      return 1;
    }
  }
  else if (uVar2 == DAT_008025d4) {
    if (*(char *)(*in_EAX + 0x89) == -1) {
      return 1;
    }
  }
  else if (uVar2 == DAT_007f8cc4) {
    iVar1 = *in_EAX;
    if ((((*(byte *)(iVar1 + 0xa0) & 1) != 0) && (*(int *)(iVar1 + 0x38) == 0)) &&
       (*(int *)(iVar1 + 0x3c) == 0)) {
      return 1;
    }
  }
  else if ((uVar2 == DAT_00802460) && (iVar1 = FUN_0054d410(*in_EAX,0,0), iVar1 == 0)) {
    return 1;
  }
  return 0;
}

