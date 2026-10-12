/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561ba0; label: FUN_00561ba0
 */

void FUN_00561ba0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  char cVar4;
  
  if (DAT_00802838 != -1) {
    *(char *)(param_1 + 0x7b5) = (char)DAT_00802838;
    cVar4 = (char)param_2;
    *(char *)(param_1 + 0x7b8) = cVar4;
    uVar2 = DAT_00804bec;
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined2 *)(param_1 + 0x7aa) = uVar2;
    if ((param_2 == 4) || (param_2 == 3)) {
      iVar3 = 1;
    }
    else {
      iVar3 = 0;
    }
    *(undefined4 *)(param_1 + 0x78c) = *(undefined4 *)(param_1 + 0x17c);
    *(undefined4 *)(param_1 + 0x788) = 0;
    *(undefined1 *)(param_1 + 0x7b9) = 1;
    *(uint *)(param_1 + 0x7bc) = iVar3 << 0x10 | *(uint *)(param_1 + 0x7bc) & 0xfffe6fff;
    if ((cVar4 != '\x06') && (cVar4 != '\a')) {
      FUN_00547f30(param_1,0);
    }
  }
  *(undefined1 *)(param_1 + 0x281) = 0;
  *(undefined2 *)(param_1 + 0x1050) = 0;
  uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x2c);
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x100000;
  *(undefined4 *)(param_1 + 0x6c) = uVar1;
  *(undefined4 *)(param_1 + 0xd48) = 0;
  *(undefined4 *)(param_1 + 0xd2c) = 0;
  *(undefined4 *)(param_1 + 0xd1c) = 0;
  FUN_0062e650(param_1 + 8,0xffffffff);
  *(undefined2 *)(param_1 + 0x278) = 0;
  *(undefined2 *)(param_1 + 0x27c) = 0;
  *(undefined1 *)(param_1 + 0x107a) = 2;
  return;
}

