/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0ad0; label: FUN_005e0ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0ad0(undefined4 *param_1)

{
  int *piVar1;
  
  if (DAT_00973fc4 != 0) {
    piVar1 = (int *)param_1[7];
    if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
      FUN_005d72b0("Display Scene : UNKNOWN (sort: %d)",*param_1);
    }
    else {
      FUN_005d72b0("Display Scene : %s (sort: %d)",*piVar1,*param_1);
    }
    FUN_005d7230("<font face=courier new>\n");
    FUN_005e09a0(3,0,0,DAT_0096d938);
  }
  return;
}

