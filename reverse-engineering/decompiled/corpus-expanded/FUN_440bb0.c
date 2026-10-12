/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440bb0; label: FUN_00440bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00440bb0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00805e24,param_2);
  if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
    iVar2 = 0;
  }
  return iVar2;
}

