/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55ffb0; label: FUN_0055ffb0
 */

undefined4 FUN_0055ffb0(undefined *param_1,int param_2)

{
  void *_Dst;
  undefined *puVar1;
  int iVar2;
  size_t _Size;
  
  iVar2 = *(int *)(param_1 + 0x110);
  FUN_00566630(0);
  if (iVar2 != 0) {
    if (((*(int *)(param_1 + 0x11c) == param_2) &&
        (*(char *)(param_2 * 0x130 + 0xa3 + DAT_00951b78) != -1)) && (DAT_0087b71c == 0)) {
      return 0;
    }
    FUN_0055f6c0(param_1);
  }
  if (DAT_0087b71c != 0) {
    puVar1 = &DAT_00942a04;
    if (param_1 != &DAT_0093d858) {
      puVar1 = &DAT_0093d858;
    }
    if ((*(int *)(puVar1 + 0x110) != 0) && (*(int *)(puVar1 + 0x11c) == param_2)) {
      FUN_0055f6c0(puVar1);
    }
  }
  iVar2 = *(int *)(param_1 + 0x108);
  _Dst = *(void **)(param_1 + 0x100);
  _memset(param_1,0,0x51ac);
  *(int *)(param_1 + 0x108) = iVar2;
  _Size = iVar2 - (int)_Dst;
  *(void **)(param_1 + 0x100) = _Dst;
  *(void **)(param_1 + 0x104) = _Dst;
  if (0 < (int)_Size) {
    _memset(_Dst,0,_Size);
  }
  *(int *)(param_1 + 0x11c) = param_2;
  *(undefined4 *)(param_1 + 0x120) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x124) = 0xffffffff;
  if (param_2 != -1) {
    iVar2 = DAT_00951b78 + param_2 * 0x130;
    *(int *)(param_1 + 0x128) = iVar2;
    iVar2 = (int)*(char *)(iVar2 + 0xa3);
    *(int *)(param_1 + 0x120) = iVar2;
    if (iVar2 != -1) {
      *(int *)(param_1 + 300) = iVar2 * 0x9c + DAT_00951354;
      *(int *)(param_1 + 0x124) =
           (int)*(char *)(*(int *)(param_1 + 0x120) * 0x9c + 0x86 + DAT_00951354);
    }
    *(undefined4 *)(param_1 + 0x2a98) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2aa0) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2aa4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2aa8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2a9c) = 0xffffffff;
    iVar2 = (int)*(char *)(param_2 * 0x130 + 200 + DAT_00951b78);
    if ((iVar2 == -1) || (0xb < iVar2)) {
      *(undefined4 *)(param_1 + 0x130) = 0;
    }
    else {
      *(int *)(param_1 + 0x130) = iVar2 * 0x2e28 + DAT_0087b2cc;
    }
    FUN_004f1f10(param_1,"levels\\");
    FUN_004f1e80(param_1,*(undefined4 *)(param_1 + 0x128));
    puVar1 = param_1 + 0x80;
    FUN_004f1f10(puVar1,param_1);
    FUN_004f1e80(puVar1,&DAT_0075a204);
    FUN_004f1e80(puVar1,*(int *)(param_1 + 0x128) + 0x40);
    FUN_00547ba0(param_1);
  }
  return 1;
}

