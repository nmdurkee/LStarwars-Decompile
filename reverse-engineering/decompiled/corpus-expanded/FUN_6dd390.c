/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd390; label: FUN_006dd390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006dd390(void)

{
  int iVar1;
  
  iVar1 = PeekMessageA((LPMSG)&DAT_02975a74,(HWND)0x0,0,0,1);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    TranslateMessage((MSG *)&DAT_02975a74);
    DispatchMessageA((MSG *)&DAT_02975a74);
    if (DAT_02975a78 == 0x12) break;
    iVar1 = PeekMessageA((LPMSG)&DAT_02975a74,(HWND)0x0,0,0,1);
  }
  return 0;
}

