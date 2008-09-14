!macro CustomCodePostInstall
	StrCmp $LANGUAGE "1061" 0 +3 ;Estonian
		WriteINIStr $INSTDIR\Data\Settings.ini "General" "LanguageCode" "et_EE"
		Goto CustomCodePostInstallEnd
	StrCmp $LANGUAGE "1034" 0 +3 ;Spanish
		WriteINIStr $INSTDIR\Data\Settings.ini "General" "LanguageCode" "es_ES"
		Goto CustomCodePostInstallEnd
	StrCmp $LANGUAGE "1049" 0 +3 ;Russian
		WriteINIStr $INSTDIR\Data\Settings.ini "General" "LanguageCode" "ru_RU"
		Goto CustomCodePostInstallEnd
	StrCmp $LANGUAGE "1043" 0 +3 ;Dutch
		WriteINIStr $INSTDIR\Data\Settings.ini "General" "LanguageCode" "nl_NL"
		Goto CustomCodePostInstallEnd
	StrCmp $LANGUAGE "1031" 0 +3 ;German
		WriteINIStr $INSTDIR\Data\Settings.ini "General" "LanguageCode" "de_DE"
		Goto CustomCodePostInstallEnd
	StrCmp $LANGUAGE "1036" 0 +3 ;French
		WriteINIStr $INSTDIR\Data\Settings.ini "General" "LanguageCode" "fr_FR"
		Goto CustomCodePostInstallEnd
	WriteINIStr $INSTDIR\Data\Settings.ini "General" "LanguageCode" "en_GB" ;=== Fallback to English
	CustomCodePostInstallEnd:
!macroend