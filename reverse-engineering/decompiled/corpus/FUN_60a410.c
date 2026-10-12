/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a410; label: FUN_0060a410
 */

void FUN_0060a410(void)

{
  int *piVar1;
  int *piVar2;
  int local_1c;
  char local_18;
  int *local_14;
  short sStack_4;
  
  FUN_006069a0();
  piVar2 = &DAT_02855078;
  do {
    if ((piVar2[1] != 0) && (piVar1 = (int *)*piVar2, piVar1 != (int *)0x0)) {
      piVar2[-1] = *piVar1;
      FUN_005fb870(piVar1,0,0);
      FUN_006e3720(&local_1c,0);
      FUN_006e22a0();
      FUN_006e45e0(0,0,1,0xff000000,0x3f800000,0);
    }
    piVar2 = piVar2 + 0xc;
  } while ((int)piVar2 < 0x2855378);
  if ((local_1c == 0) || (*(int *)(local_1c + 0x28) == 0)) {
    if (local_14 == (int *)0x0) goto LAB_0060a4a3;
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_14 = (int *)0x0;
LAB_0060a4a3:
  if (local_1c == 0) {
    (&DAT_00986a88)[sStack_4] = 0;
    return;
  }
  if (local_18 != '\0') {
    FUN_005f7b40(local_1c);
    (&DAT_00986a88)[sStack_4] = 0;
    return;
  }
  (&DAT_00986a88)[sStack_4] = 0;
  return;
}

