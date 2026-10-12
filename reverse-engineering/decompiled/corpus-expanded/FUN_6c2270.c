/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2270; label: FUN_006c2270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2270(void)

{
  char *pcVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076fa04;
  pcVar1 = (char *)in_ECX[4];
  if (pcVar1 != (char *)0x0) {
    FUN_006334d0(pcVar1,(int)*pcVar1);
  }
  pcVar1 = (char *)in_ECX[3];
  if (pcVar1 != (char *)0x0) {
    FUN_006334d0(pcVar1,(int)*pcVar1);
  }
  return;
}

