/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f2dc0; label: FUN_004f2dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f2dc0(undefined1 *param_1,ushort *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_2 != (ushort *)0x0) && (param_1 != (undefined1 *)0x0)) {
    *param_1 = 0;
    uVar2 = *param_2;
    puVar1 = param_2;
    while (uVar2 != 0) {
      uVar2 = *puVar1;
      if ((uVar2 & 0xff00) == 0) {
        param_1[iVar3] = (char)*puVar1;
      }
      else if (uVar2 < 0x201a) {
        if (uVar2 == 0x2019) {
          param_1[iVar3] = 0x92;
        }
        else if (uVar2 == 0x2013) {
          param_1[iVar3] = 0x96;
        }
        else {
          if (uVar2 != 0x2018) goto LAB_004f2e28;
          param_1[iVar3] = 0x91;
        }
      }
      else if (uVar2 == 0x2026) {
        param_1[iVar3] = 0x85;
      }
      else if (uVar2 == 0x2122) {
        param_1[iVar3] = 0x99;
      }
      else {
LAB_004f2e28:
        param_1[iVar3] = 0x3f;
      }
      iVar3 = iVar3 + 1;
      puVar1 = param_2 + iVar3;
      uVar2 = param_2[iVar3];
    }
    param_1[iVar3] = 0;
  }
  return;
}

