/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f34c0; label: FUN_004f34c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f34c0(void)

{
  short sVar1;
  int iVar2;
  short in_DX;
  
  iVar2 = 0;
  sVar1 = DAT_008004ac;
  while( true ) {
    if (sVar1 == 0) {
      return 0;
    }
    if (sVar1 == in_DX) break;
    sVar1 = (&DAT_008004ae)[iVar2];
    iVar2 = iVar2 + 1;
  }
  return 1;
}

