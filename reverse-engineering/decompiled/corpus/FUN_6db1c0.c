/* Ghidra analysis pseudocode, not original source.
 * ev_7393eb289fae971e4c9d676939847dbe45fbc997f5b4ac5470a7ef95c2a601ec
 * Entry: 0x6db1c0; label: FUN_006db1c0
 */

void FUN_006db1c0(void)

{
  FILE *_File;
  int in_ECX;
  
  _File = _fopen((char *)(in_ECX + 4),"w");
  if (_File != (FILE *)0x0) {
    _fprintf(_File,"FileVersion            %d\n",DAT_00826000);
    _fprintf(_File,"ScreenWidth            %d\n",*(undefined4 *)(in_ECX + 0x404));
    _fprintf(_File,"ScreenHeight           %d\n",*(undefined4 *)(in_ECX + 0x408));
    _fprintf(_File,"WindowWidth            %d\n",*(undefined4 *)(in_ECX + 0x40c));
    _fprintf(_File,"WindowHeight           %d\n",*(undefined4 *)(in_ECX + 0x410));
    _fprintf(_File,"WindowLeft             %d\n",*(undefined4 *)(in_ECX + 0x414));
    _fprintf(_File,"WindowTop              %d\n",*(undefined4 *)(in_ECX + 0x418));
    _fprintf(_File,"ScreenRefreshRate      %d\n",*(undefined4 *)(in_ECX + 0x41c));
    _fprintf(_File,"FSAA                   %d\n",*(undefined4 *)(in_ECX + 0x420));
    _fprintf(_File,"Widescreen             %d\n",*(undefined4 *)(in_ECX + 0x424));
    _fprintf(_File,"SFXVolume              %d\n",*(undefined4 *)(in_ECX + 0x428));
    _fprintf(_File,"MusicVolume            %d\n",*(undefined4 *)(in_ECX + 0x42c));
    _fprintf(_File,"MasterVolume           %d\n",*(undefined4 *)(in_ECX + 0x430));
    _fprintf(_File,"MusicEnabled           %d\n",(uint)(*(char *)(in_ECX + 0x434) != '\0'));
    _fprintf(_File,"MouseSensitivity       %d\n",*(undefined4 *)(in_ECX + 0x438));
    _fprintf(_File,"InvertY                %d\n",(uint)*(byte *)(in_ECX + 0x43c));
    _fprintf(_File,"Vibration              %d\n",(uint)*(byte *)(in_ECX + 0x43d));
    _fprintf(_File,"BloomMethod            %d\n",*(undefined4 *)(in_ECX + 0x440));
    _fprintf(_File,"DesiredBloomMethod     %d\n",*(undefined4 *)(in_ECX + 0x444));
    _fprintf(_File,"BloomEnabled           %d\n",(uint)(*(char *)(in_ECX + 0x448) != '\0'));
    _fprintf(_File,"ShadowMethod           %d\n",*(undefined4 *)(in_ECX + 0x44c));
    _fprintf(_File,"DesiredShadowMethod    %d\n",*(undefined4 *)(in_ECX + 0x450));
    _fprintf(_File,"ShadowsEnabled         %d\n",(uint)(*(char *)(in_ECX + 0x454) != '\0'));
    _fprintf(_File,"SpeedBlurSupported     %d\n",(uint)(*(char *)(in_ECX + 0x455) != '\0'));
    _fprintf(_File,"SpeedBlurEnabled       %d\n",(uint)(*(char *)(in_ECX + 0x456) != '\0'));
    _fprintf(_File,"UseHires               %d\n",(uint)(*(char *)(in_ECX + 0x457) != '\0'));
    _fprintf(_File,"UseHiresPending        %d\n",(uint)(*(char *)(in_ECX + 0x458) != '\0'));
    _fprintf(_File,"ForceShaderModel       %d\n",*(undefined4 *)(in_ECX + 0x45c));
    _fclose(_File);
  }
  return;
}

