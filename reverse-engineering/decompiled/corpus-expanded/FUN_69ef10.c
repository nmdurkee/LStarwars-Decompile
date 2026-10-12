/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69ef10; label: FUN_0069ef10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069ef10(void)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x18) <= *(int *)(unaff_ESI + 0x1c) + in_ECX) {
    iVar1 = *(int *)(unaff_ESI + 0x18) + 0x20 + in_ECX;
    *(int *)(unaff_ESI + 0x18) = iVar1;
    pvVar2 = _realloc(*(void **)(unaff_ESI + 0x10),iVar1 * 4);
    *(void **)(unaff_ESI + 0x10) = pvVar2;
    pvVar2 = _realloc(*(void **)(unaff_ESI + 0x14),*(int *)(unaff_ESI + 0x18) * 8);
    *(void **)(unaff_ESI + 0x14) = pvVar2;
  }
  return;
}

