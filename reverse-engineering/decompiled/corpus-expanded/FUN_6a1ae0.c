/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1ae0; label: FUN_006a1ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a1ae0(void *param_1)

{
  int iVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (void *)0x0) {
    iVar1 = *(int *)((int)param_1 + 4);
    if (iVar1 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar1 + 0x1c);
    }
    _Memory = *(int **)((int)param_1 + 0x68);
    if (_Memory != (int *)0x0) {
      if (*_Memory != 0) {
        FUN_006b0bb0(*_Memory);
        _free((void *)*_Memory);
      }
      if ((undefined4 *)_Memory[3] != (undefined4 *)0x0) {
        FUN_006afc50(*(undefined4 *)_Memory[3]);
        _free(*(void **)_Memory[3]);
        _free((void *)_Memory[3]);
      }
      if ((undefined4 *)_Memory[4] != (undefined4 *)0x0) {
        FUN_006afc50(*(undefined4 *)_Memory[4]);
        _free(*(void **)_Memory[4]);
        _free((void *)_Memory[4]);
      }
      if (_Memory[0xc] != 0) {
        if ((iVar5 != 0) && (iVar2 = 0, 0 < *(int *)(iVar5 + 0x10))) {
          piVar3 = (int *)(iVar5 + 800);
          do {
            (**(code **)((&PTR_DAT_00817010)[*piVar3] + 0x10))
                      (*(undefined4 *)(_Memory[0xc] + iVar2 * 4));
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 1;
          } while (iVar2 < *(int *)(iVar5 + 0x10));
        }
        _free((void *)_Memory[0xc]);
      }
      if (_Memory[0xd] != 0) {
        if ((iVar5 != 0) && (iVar2 = 0, 0 < *(int *)(iVar5 + 0x14))) {
          piVar3 = (int *)(iVar5 + 0x520);
          do {
            (**(code **)((&PTR_DAT_00817018)[*piVar3] + 0x10))
                      (*(undefined4 *)(_Memory[0xd] + iVar2 * 4));
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 1;
          } while (iVar2 < *(int *)(iVar5 + 0x14));
        }
        _free((void *)_Memory[0xd]);
      }
      if (_Memory[0xe] != 0) {
        if ((iVar5 != 0) && (iVar2 = 0, 0 < *(int *)(iVar5 + 0x1c))) {
          iVar4 = 0;
          do {
            FUN_006a53c0(_Memory[0xe] + iVar4);
            iVar2 = iVar2 + 1;
            iVar4 = iVar4 + 0x34;
          } while (iVar2 < *(int *)(iVar5 + 0x1c));
        }
        _free((void *)_Memory[0xe]);
      }
      if (_Memory[0xf] != 0) {
        FUN_006a3e80(_Memory[0xf]);
      }
      FUN_006b0450(_Memory + 0x14);
      FUN_006af260(_Memory + 5);
      FUN_006af260(_Memory + 8);
    }
    if (*(int *)((int)param_1 + 8) != 0) {
      if ((iVar1 != 0) && (iVar5 = 0, 0 < *(int *)(iVar1 + 4))) {
        do {
          if (*(int *)(*(int *)((int)param_1 + 8) + iVar5 * 4) != 0) {
            _free(*(void **)(*(int *)((int)param_1 + 8) + iVar5 * 4));
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(iVar1 + 4));
      }
      _free(*(void **)((int)param_1 + 8));
      if (*(void **)((int)param_1 + 0xc) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0xc));
      }
    }
    if (_Memory != (int *)0x0) {
      if ((void *)_Memory[0x10] != (void *)0x0) {
        _free((void *)_Memory[0x10]);
      }
      if ((void *)_Memory[0x11] != (void *)0x0) {
        _free((void *)_Memory[0x11]);
      }
      if ((void *)_Memory[0x12] != (void *)0x0) {
        _free((void *)_Memory[0x12]);
      }
      _free(_Memory);
    }
    _memset(param_1,0,0x70);
  }
  return;
}

