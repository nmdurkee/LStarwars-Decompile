/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e8430; label: FUN_005e8430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e8430(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0080bd34;
  iVar1 = DAT_0080bd30;
  if ((DAT_0080bbe0 != '\0') && (DAT_0080bbe1 != '\0')) {
    DAT_0080bd30 = DAT_0080bd34;
    DAT_0080bd34 = iVar1;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined1 *)(iVar2 + 0x10) = 0;
    _DAT_0080bd40 = 0;
    _DAT_0080bd44 = 0;
  }
  return;
}

