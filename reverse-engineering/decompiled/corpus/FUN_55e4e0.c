/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e4e0; label: FUN_0055e4e0
 */

void FUN_0055e4e0(int param_1)

{
  ushort *puVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined1 *)(param_1 + 0x100) = 0xff;
  if ((*(byte *)(param_1 + 0x75e) & 1) == 0) {
    *(undefined4 *)(param_1 + 0x678) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x678) = 0x3f800000;
  }
  *(undefined4 *)(param_1 + 0x67c) = 0x40a00000;
  *(undefined1 *)(param_1 + 0x76f) = 0;
  *(undefined4 *)(param_1 + 0x66c) = 0;
  *(undefined1 *)(param_1 + 0xf1) = 0xff;
  *(undefined4 *)(param_1 + 0x674) = 0;
  *(undefined1 *)(param_1 + 0xf5) = 0;
  *(undefined4 *)(param_1 + 0x664) = 0;
  *(undefined1 *)(param_1 + 0xf4) = 0;
  puVar1 = (ushort *)(*(int *)(param_1 + 0x5e0) + 0x5a);
  *puVar1 = *puVar1 & 0xfffb;
  puVar1 = (ushort *)(*(int *)(param_1 + 0x5e0) + 0x5a);
  *puVar1 = *puVar1 & 0xffef;
  *(uint *)(param_1 + 0x75c) = *(uint *)(param_1 + 0x75c) & 0xfffffbff;
  *(undefined4 *)(param_1 + 0x65c) = 0;
  *(undefined4 *)(param_1 + 0x648) = 0;
  iVar2 = FUN_0054fa60();
  *(undefined4 *)(param_1 + 0x694) = 0;
  *(undefined4 *)(param_1 + 0x698) = 0;
  *(undefined4 *)(param_1 + 0x670) = 0;
  *(undefined4 *)(param_1 + 0x6d0) = 0;
  *(undefined4 *)(param_1 + 0x6e8) = 0;
  *(char *)(param_1 + 0x77d) = (char)((int)(iVar2 + (iVar2 >> 0x1f & 0x7fffU)) >> 0xf);
  *(undefined4 *)(param_1 + 0x700) = 0;
  *(undefined4 *)(param_1 + 0x714) = 0;
  *(undefined2 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0x720) = 0;
  *(undefined1 *)(param_1 + 0xee) = 0;
  *(undefined1 *)(param_1 + 0x76e) = 0;
  *(undefined4 *)(param_1 + 0x724) = 0;
  *(undefined4 *)(param_1 + 0x60c) = 0;
  *(undefined2 *)(param_1 + 0x74c) = 0xffff;
  *(undefined2 *)(param_1 + 0x750) = 0xffff;
  *(undefined2 *)(param_1 + 0x752) = 0xffff;
  return;
}

