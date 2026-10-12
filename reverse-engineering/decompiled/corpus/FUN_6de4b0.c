/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6de4b0; label: FUN_006de4b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006de4b0(HINSTANCE param_1,int param_2,ushort param_3)

{
  ATOM AVar1;
  HICON lParam;
  HWND hWnd;
  uint X;
  uint Y;
  
  lParam = LoadIconA(param_1,(LPCSTR)(uint)param_3);
  _DAT_02975a74 = 0;
  DAT_02975a78 = 0;
  _DAT_02975a7c = 0;
  _DAT_02975a80 = 0;
  _DAT_02975a84 = 0;
  _DAT_02975a88 = 0;
  _DAT_02975a8c = 0;
  _DAT_02975a44 = 0x30;
  _DAT_02975a48 = 3;
  _DAT_02975a4c = FUN_006de1c0;
  _DAT_02975a50 = 0;
  _DAT_02975a54 = 0;
  _DAT_02975a58 = param_1;
  _DAT_02975a5c = lParam;
  _DAT_02975a70 = lParam;
  _DAT_02975a60 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _DAT_02975a64 = 6;
  _DAT_02975a68 = 0;
  _DAT_02975a6c = "TTalesWindow";
  AVar1 = RegisterClassExA((WNDCLASSEXA *)&DAT_02975a44);
  if (AVar1 == 0) {
    MessageBoxA((HWND)0x0,"Window Registration Failed!","Error!",0x30);
    return 0;
  }
  X = DAT_00826484;
  if ((int)DAT_00826484 < 0) {
    X = (uint)(DAT_02976bd0 - DAT_0082647c) >> 1;
  }
  Y = DAT_00826488;
  if ((int)DAT_00826488 < 0) {
    Y = (uint)(DAT_02976bd4 - DAT_00826480) >> 1;
  }
  hWnd = CreateWindowExA(0,"TTalesWindow",PTR_s_TitleNotSet_00827614,
                         (DWORD)(&DAT_00cf0000 + (-(uint)(DAT_02976720 != 1) & 0x8f310000)),X,Y,
                         DAT_0082647c,DAT_00826480,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0);
  if (hWnd == (HWND)0x0) {
    MessageBoxA((HWND)0x0,"Window Creation Failed!","Error!",0x30);
    return 0;
  }
  ShowWindow(hWnd,param_2);
  UpdateWindow(hWnd);
  DAT_00924864 = hWnd;
  ShowWindow(hWnd,param_2);
  UpdateWindow(hWnd);
  SendMessageA(hWnd,0x80,1,(LPARAM)lParam);
  SendMessageA(hWnd,0x80,0,(LPARAM)lParam);
  return 1;
}

