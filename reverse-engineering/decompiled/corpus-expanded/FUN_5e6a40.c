/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e6a40; label: FUN_005e6a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005e6a40(undefined4 *param_1)

{
  float10 fVar1;
  
  if ((DAT_009737ec != 0) && (DAT_009738e8 != 0)) {
    DAT_009738e8 = 0;
    fVar1 = (float10)FUN_005c4f10(param_1);
    return fVar1;
  }
  *param_1 = 1;
  return (float10)0;
}

