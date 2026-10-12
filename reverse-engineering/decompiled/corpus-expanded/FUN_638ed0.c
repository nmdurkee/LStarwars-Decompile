/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638ed0; label: FUN_00638ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638ed0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_02913814;
  if (DAT_02913814 != 0) {
    uVar2 = FUN_006e6b90();
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
  }
  return;
}

