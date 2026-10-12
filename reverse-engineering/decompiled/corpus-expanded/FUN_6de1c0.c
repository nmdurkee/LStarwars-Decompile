/* Ghidra pseudocode, not original source.
 * ev_ed8379466d952c1ee28599ad459362d78654b4c0ec0ca4c18c489e481aca6c51
 * Entry: 0x6de1c0; label: FUN_006de1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_006de1c0(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  float fVar1;
  uint lParam;
  LRESULT LVar2;
  DWORD dwStyle;
  int iVar3;
  BOOL bMenu;
  tagRECT tStack_10;
  
  lParam = param_4;
  iVar3 = 0;
  if (0 < DAT_02975c5c) {
    do {
      param_4 = 0;
      LVar2 = (*(code *)(&DAT_029759d8)[iVar3])(param_1,param_2,param_3,lParam,&param_4);
      if (param_4 != 0) {
        return LVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_02975c5c);
  }
  if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_006d6a10((int)((int)lParam >> 1 & 0xff80ffffU | lParam) >> 0x10 & 0xff);
      return 0;
    }
    switch(param_2) {
    case 2:
      DAT_0092485c = 1;
      PostQuitMessage(0);
      return 0;
    case 5:
      DAT_00827630 = lParam & 0xffff;
      bMenu = 0;
      DAT_00827634 = lParam >> 0x10;
      tStack_10.left = 0;
      tStack_10.top = 0;
      tStack_10.right = DAT_00827630;
      tStack_10.bottom = DAT_00827634;
      dwStyle = GetWindowLongA(param_1,-0x10);
      AdjustWindowRect(&tStack_10,dwStyle,bMenu);
      FUN_006daf10(tStack_10.right - tStack_10.left);
      FUN_006daf20(tStack_10.bottom - tStack_10.top);
      return 0;
    case 6:
      DAT_00827610 = (uint)((short)param_3 != 0);
      return 0;
    case 0x10:
      DAT_0092485c = 1;
      FUN_006de060();
                    /* WARNING: Subroutine does not return */
      _exit(0);
    case 0x20:
      if (DAT_02976720 == 1) {
        return 1;
      }
      SetCursor((HCURSOR)0x0);
      return 1;
    }
  }
  else if (param_2 < 0x201) {
    if (param_2 == 0x200) {
      fVar1 = (float)(int)DAT_00827630;
      if ((int)DAT_00827630 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      _DAT_02975c40 = (float)(lParam & 0xffff) / fVar1;
      fVar1 = (float)(int)DAT_00827634;
      if ((int)DAT_00827634 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      _DAT_02975c44 = (float)(lParam >> 0x10) / fVar1;
      return 0;
    }
    if (param_2 == 0x101) {
      FUN_006d6d70((int)((int)lParam >> 1 & 0xff80ffffU | lParam) >> 0x10 & 0xff);
      return 0;
    }
    if (param_2 == 0x104) {
      return 1;
    }
  }
  else {
    if (param_2 == 0x219) {
      if ((param_3 != 7) && (param_3 != 0x8000)) {
        return 1;
      }
      FUN_006d5950(0x40000000,3);
      return 1;
    }
    if (param_2 == 0x281) {
      LVar2 = DefWindowProcA(param_1,0x281,param_3,0);
      return LVar2;
    }
  }
  LVar2 = DefWindowProcA(param_1,param_2,param_3,lParam);
  return LVar2;
}

