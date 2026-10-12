/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6dd390; label: FUN_006dd390
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

