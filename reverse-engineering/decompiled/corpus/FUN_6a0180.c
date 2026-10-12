/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a0180; label: FUN_006a0180
 */

void FUN_006a0180(undefined4 *param_1)

{
  void *_Memory;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  _Memory = (void *)param_1[7];
  if (_Memory != (void *)0x0) {
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 8)) {
      puVar2 = (undefined4 *)((int)_Memory + 0x20);
      do {
        if ((void *)*puVar2 != (void *)0x0) {
          _free((void *)*puVar2);
        }
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 8));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0xc)) {
      piVar1 = (int *)((int)_Memory + 0x220);
      do {
        if (*piVar1 != 0) {
          (**(code **)((&PTR_PTR_00817024)[piVar1[-0x40]] + 8))(*piVar1);
        }
        iVar4 = iVar4 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0xc));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0x10)) {
      piVar1 = (int *)((int)_Memory + 0x420);
      do {
        if (*piVar1 != 0) {
          (**(code **)((&PTR_DAT_00817010)[piVar1[-0x40]] + 0xc))(*piVar1);
        }
        iVar4 = iVar4 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0x10));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0x14)) {
      piVar1 = (int *)((int)_Memory + 0x620);
      do {
        if (*piVar1 != 0) {
          (**(code **)((&PTR_DAT_00817018)[piVar1[-0x40]] + 0xc))(*piVar1);
        }
        iVar4 = iVar4 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0x14));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0x18)) {
      iVar3 = 0;
      piVar1 = (int *)((int)_Memory + 0x720);
      do {
        if (*piVar1 != 0) {
          FUN_006a87c0(*piVar1);
        }
        if (*(int *)((int)_Memory + 0xb20) != 0) {
          FUN_006a87e0(*(int *)((int)_Memory + 0xb20) + iVar3);
        }
        iVar4 = iVar4 + 1;
        piVar1 = piVar1 + 1;
        iVar3 = iVar3 + 0x2c;
      } while (iVar4 < *(int *)((int)_Memory + 0x18));
    }
    if (*(void **)((int)_Memory + 0xb20) != (void *)0x0) {
      _free(*(void **)((int)_Memory + 0xb20));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0x1c)) {
      puVar2 = (undefined4 *)((int)_Memory + 0xb24);
      do {
        FUN_006a3ee0(*puVar2);
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0x1c));
    }
    _free(_Memory);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}

