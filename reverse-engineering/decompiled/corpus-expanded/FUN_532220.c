/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x532220; label: FUN_00532220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00532220(void *param_1,int param_2)

{
  char *pcVar1;
  void *_Dst;
  int *piVar2;
  
  _Dst = param_1;
  if ((param_1 != (void *)0x0) && (param_2 != 0)) {
    if (*(int *)((int)param_1 + 0xb0) != 0) {
      pcVar1 = (char *)(*(int *)((int)param_1 + 0xb0) + 8);
      *pcVar1 = *pcVar1 + -1;
      if (*(char *)(*(int *)((int)param_1 + 0xb0) + 8) < '\x02') {
        FUN_00525b80();
      }
      *(undefined4 *)((int)param_1 + 0xb0) = 0;
    }
    piVar2 = (int *)((int)param_1 + 0x30);
    param_1 = (void *)0x8;
    do {
      if (*piVar2 != 0) {
        FUN_00522dc0();
      }
      piVar2 = piVar2 + 3;
      param_1 = (void *)((int)param_1 + -1);
    } while (param_1 != (void *)0x0);
    FUN_004f1410(param_2 + 0x18,_Dst);
    *(short *)(param_2 + 0x36) = *(short *)(param_2 + 0x36) + -1;
    _memset(_Dst,0,0xb4);
    FUN_004f1310(DAT_009238e4 + 0x3187c,_Dst);
  }
  return;
}

