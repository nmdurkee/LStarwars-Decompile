/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cde70; label: FUN_006cde70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cde70(byte param_1)

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
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0xd0);
  }
  return;
}

