/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a200; label: FUN_0055a200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_0055a200(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  char *pcVar2;
  
  if (((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) && (param_2 != 0)) {
    if (((int)(uint)*(byte *)(param_2 + 6) < *DAT_0093b268) &&
       (pcVar1 = *(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x4c + DAT_0093b268[2]),
       pcVar1 != (code *)0x0)) {
      pcVar2 = (char *)(*pcVar1)(param_2,param_3);
      return pcVar2;
    }
    return "default";
  }
  return (char *)0x0;
}

