/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44d390; label: FUN_0044d390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044d390(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if ((param_6 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_0075782c);
        if (iVar1 != 0) {
          iVar3 = iVar1 + 5;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    iVar3 = FUN_005171b0(param_1,iVar3);
    if (iVar3 != 0) {
      piVar2 = &DAT_0093d7f0;
      do {
        iVar3 = *piVar2;
        if (((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 1) != 0)) &&
           ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0)) {
          FUN_0051a7c0(iVar3 + 0x2c8,*(undefined4 *)(*(int *)(param_1 + 0x10) + 8));
          FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar3,iVar3 + 0x2c8,0xff,
                       (int)*(char *)(iVar3 + 0x281));
        }
        piVar2 = piVar2 + 1;
      } while ((int)piVar2 < 0x93d810);
    }
    return 1;
  }
  return 1;
}

