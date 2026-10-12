/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a360; label: FUN_0055a360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055a360(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (((DAT_0093b268 != 0) && (param_2 != 0)) &&
     (pcVar1 = *(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 100 + *(int *)(DAT_0093b268 + 8)),
     pcVar1 != (code *)0x0)) {
    uVar2 = (*pcVar1)(param_2);
    return uVar2;
  }
  return 0;
}

