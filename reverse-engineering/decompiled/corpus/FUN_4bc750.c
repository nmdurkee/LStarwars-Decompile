/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bc750; label: FUN_004bc750
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bc750(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  FUN_004bc2f0(param_1);
  iVar1 = *(int *)(param_1 + 0x5168);
  if ((iVar1 != 0) && (DAT_0093d810 != 0)) {
    if (_DAT_007fc450 <= *(float *)(DAT_0093d810 + 100)) {
      if (*(char *)(iVar1 + 0x77e3) == '\x01') {
        return;
      }
      *(undefined1 *)(iVar1 + 0x77e3) = 1;
    }
    else {
      if (*(char *)(iVar1 + 0x77e3) == -1) {
        return;
      }
      *(undefined1 *)(iVar1 + 0x77e3) = 0xff;
    }
    iVar3 = 0;
    if ('\0' < *(char *)(iVar1 + 0x77e0)) {
      iVar2 = iVar1 + 0x139;
      do {
        if (_DAT_007fc450 <= *(float *)(DAT_0093d810 + 100)) {
          bVar4 = *(char *)(iVar2 + 1) == -1;
        }
        else {
          bVar4 = *(char *)(iVar2 + 1) == '\x01';
        }
        *(bool *)iVar2 = bVar4;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x140;
      } while (iVar3 < *(char *)(iVar1 + 0x77e0));
    }
  }
  return;
}

