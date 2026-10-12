/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44cf20; label: FUN_0044cf20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044cf20(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = 1e+09;
  local_8 = 1e+09;
  iVar3 = 0;
  local_4 = 1e+09;
  local_10 = 0xffffffff;
  local_14 = 0x21;
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar3 = *piVar2;
  }
  if (param_6 != 0) {
    iVar4 = 0;
    iVar1 = 0x21;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_0075785c);
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757858);
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757854);
              if (iVar1 == 0) {
                iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_0075772c);
                if (iVar1 != 0) {
                  local_14 = FUN_0062c3b0(DAT_0093b0dc,iVar1 + 5);
                }
              }
              else {
                fVar5 = (float10)FUN_005147c0(param_2,iVar1 + 2);
                local_4 = (float)fVar5;
              }
            }
            else {
              fVar5 = (float10)FUN_005147c0(param_2,iVar1 + 2);
              local_8 = (float)fVar5;
            }
          }
          else {
            fVar5 = (float10)FUN_005147c0(param_2,iVar1 + 2);
            local_c = (float)fVar5;
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar2;
        }
        iVar4 = iVar4 + 1;
        iVar1 = local_14;
      } while (iVar4 < param_5);
    }
    if (((local_c != 1e+09) && (local_8 != 1e+09)) && (local_4 != 1e+09)) {
      FUN_00690460(&local_10,
                   *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + iVar1 * 0x14),
                   &local_c,1);
      return 1;
    }
    if (iVar3 != 0) {
      FUN_00690460(&local_10,
                   *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + iVar1 * 0x14),
                   iVar3 + 0x80,1);
    }
  }
  return 1;
}

