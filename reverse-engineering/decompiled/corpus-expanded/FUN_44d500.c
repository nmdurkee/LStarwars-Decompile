/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44d500; label: FUN_0044d500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044d500(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0xffffffff;
  if (param_6 != 0) {
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),&DAT_00757cf4);
        if (iVar1 != 0) {
          FUN_005147c0(param_2,iVar1 + 3);
          uVar2 = FUN_006e6b90();
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    FUN_00576960(uVar2);
  }
  return 1;
}

