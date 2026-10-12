/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f2ee0; label: FUN_004f2ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f2ee0(undefined2 *param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  *param_1 = 0;
  if (param_2 != (byte *)0x0) {
    bVar2 = *param_2;
    while (bVar2 != 0) {
      param_1[iVar3] = (ushort)bVar2;
      iVar1 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      bVar2 = param_2[iVar1];
    }
    param_1[iVar3] = 0;
  }
  return;
}

