/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69eee0; label: FUN_0069eee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069eee0(void)

{
  size_t _NewSize;
  void *pvVar1;
  int in_ECX;
  undefined4 *unaff_ESI;
  
  if ((int)unaff_ESI[1] <= unaff_ESI[2] + in_ECX) {
    _NewSize = unaff_ESI[1] + 0x400 + in_ECX;
    unaff_ESI[1] = _NewSize;
    pvVar1 = _realloc((void *)*unaff_ESI,_NewSize);
    *unaff_ESI = pvVar1;
  }
  return;
}

